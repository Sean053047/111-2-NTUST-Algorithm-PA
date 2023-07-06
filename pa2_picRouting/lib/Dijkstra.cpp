#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <cmath>
#include <list>
#include <map>
#include "../header/utils.h"
#include "../header/customized.h"

using namespace std;
vector<vector<Grid>> create_graph(int row, int col)
{
    vector<vector<Grid>> G;
    G.resize(row);
    for (int i = 0; i < row; ++i)
    {
        G[i].resize(col);
        for (int j = 0; j < col; ++j)
        {
            G[i][j].row = i;
            G[i][j].col = j;
            G[i][j].weight = numeric_limits<int>::max();
            G[i][j].pre = nullptr;
        }
    }
    return G;
}

void initialize(map<string, int> &condition, list<Grid *> &gridList, vector<vector<Grid>> &Graph, list<int> path_order, map<int, vector<int>> &net, int pid)
{
    Graph[net[pid][1]][net[pid][0]].weight = 0;
    // * 解決當輸入檔案中，有兩個接線點相同的時候，weight 值因為設計上問題導致不如預期。
    for (int i : path_order)
    {
        if (i == pid)
            break;

        bool double_endpoint = (net[pid][3] == net[i][1] && net[pid][2] == net[i][0]) || (net[pid][3] == net[i][3] && net[pid][2] == net[i][2]);
        bool double_startpoint = (net[pid][1] == net[i][1] && net[pid][0] == net[i][0]) || (net[pid][1] == net[i][3] && net[pid][0] == net[i][2]);
        if (double_endpoint)
        {
            Graph[net[pid][1]][net[pid][0]].weight += condition["crossing"];
        }
        if (double_startpoint)
        {
            Graph[net[pid][1]][net[pid][0]].weight += condition["crossing"];
        }
    }
    for (vector<Grid> &row : Graph)
    {
        for (Grid &g : row)
        {
            gridList.push_back(&g);
        }
    }
    gridList.sort(Grid());
}

void Relax(vector<vector<Grid>> &Graph, map<string, int> &condition, vector<vector<int>> &discover, int y0, int x0, int y1, int x1)
{
    int w = condition["propagation"];
    if (Graph[y0][x0].pre != nullptr)
    {
        if ((abs(y1 - Graph[y0][x0].pre->row) == 1 and abs(x1 - Graph[y0][x0].pre->col) == 1))
        {
            w += condition["bending"];
        }
    }
    if (discover[y1][x1] != 0)
    {
        w += condition["crossing"];
    }
    if (Graph[y1][x1].weight > Graph[y0][x0].weight + w)
    {
        Graph[y1][x1].weight = Graph[y0][x0].weight + w;
        Graph[y1][x1].pre = &Graph[y0][x0];
    }
}

void update_path(vector<vector<Grid>> &Graph, vector<vector<int>> &discover, vector<Grid> &SubPath, int y, int x)
{
    if (Graph[y][x].pre != nullptr)
    {
        update_path(Graph, discover, SubPath, Graph[y][x].pre->row, Graph[y][x].pre->col);
    }
    discover[y][x] = 1;
    SubPath.push_back(Graph[y][x]);
}

void show_path(vector<vector<Grid>> &Graph, int y, int x)
{
    if (Graph[y][x].pre != nullptr)
    {
        show_path(Graph, Graph[y][x].pre->row, Graph[y][x].pre->col);
    }
    cout << Graph[y][x].row << " " << Graph[y][x].col << endl;
}

list<int> reorder_path(map<int, vector<int>> &net, string judge = "None")
{
    // * judge = "None" : path_order為讀取順序
    // * judge = "Smaller" : path_order為Euclidean distance 較小的優先
    // * judge = "Bigger" : path_order為Euclidean distance 較大的優先

    list<int> path_order;
    if (judge == "None")
    {
        for (int i = 0; i < net.size(); ++i)
        {
            path_order.push_back(i);
        }
    }
    else
    {
        list<Path_dist> pathDist;
        for (int i = 0; i < net.size(); ++i)
        {
            double dist = sqrt(pow(net[i][0] - net[i][2], 2) + pow(net[i][1] - net[i][3], 2));
            Path_dist var_p = {.pid = i, .dist = dist, .judge = judge};
            pathDist.push_back(var_p);
        }
        pathDist.sort(Path_dist());
        for (Path_dist p : pathDist)
        {
            path_order.push_back(p.pid);
        }
    }
    return path_order;
}

vector<vector<Grid>> Dijkstra(map<string, int> &condition, map<int, vector<int>> &net)
{
    // * discover 紀錄有哪些點已經有路線，有則為1; 沒有為0。 初始化時，會先把所有以確認的接點的Grid設為1。
    vector<vector<int>> discover = vector_2D_create(condition["row"], condition["col"]);
    for (int key = 0; key < condition["num"]; ++key)
    {
        discover[net[key][1]][net[key][0]] = 1;
        discover[net[key][3]][net[key][2]] = 1;
    }

    // * Path 紀錄每條路徑的最佳解
    vector<vector<Grid>> Path;
    Path.resize(condition["num"]);

    list<int> path_order = reorder_path(net, "Smaller");

    for (int i : path_order)
    {
        // * Initialize
        vector<vector<Grid>> Graph = create_graph(condition["row"], condition["col"]);
        list<Grid *> gridList;

        initialize(condition, gridList, Graph, path_order, net, i);
        discover[net[i][3]][net[i][2]] = 0;

        int y;
        int x;
        Grid *min;
        // * Weight update=> Dijkstra's algorithm
        while (!(gridList.empty()))
        {
            // * Extract the grid with minimum weight
            gridList.sort(Grid());
            min = gridList.front();
            gridList.pop_front();

            y = min->row;
            x = min->col;
            // * Relax all 4-connected pixels.
            if (y != 0)
            {
                Relax(Graph, condition, discover, y, x, y - 1, x);
            }
            if (x != 0)
            {
                Relax(Graph, condition, discover, y, x, y, x - 1);
            }
            if (y != condition["row"] - 1)
            {
                Relax(Graph, condition, discover, y, x, y + 1, x);
            }
            if (x != condition["col"] - 1)
            {
                Relax(Graph, condition, discover, y, x, y, x + 1);
            }
        }

        y = net[i][3];
        x = net[i][2];
        update_path(Graph, discover, Path[i], y, x);
        cout << "Path " << i << "\tweight: " << Path[i][Path[i].size() - 1].weight << endl;
    }

    return Path;
}
