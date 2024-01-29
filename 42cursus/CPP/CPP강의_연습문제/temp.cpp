#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef struct s_node
{
    int self;
    int parents;
    int child1;
    int child2;
}t_node;

void greedy(t_node *node, int ship, int wolf, int num, int *max, int flag)
{       
    if (node[num].self == 0)
        ship++;
    else if(node[num].self == 1)
        wolf++;
    node[num].self = -1;
    if (ship == wolf)
    {
            cout << max <<endl;
        if (*max < ship)
            *max = ship;
        return ;
    }
    //child1
    if(node[num].child1 != 0 && flag != node[num].child1)
        greedy(node, ship, wolf, node[num].child1, max, num);
    //child2
    if(node[num].child2 != 0 && flag != node[num].child2)
        greedy(node, ship, wolf, node[num].child2, max, num);
    //parent
    if(node[num].parents != -1)
    greedy(node, ship, wolf, node[num].parents, max, num);
        // 1.child ship++ or wolf++
        // 2.child2
        // 3.par
}
                //     10
                // 11     20
                //      30

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int num = info.size();
    
    t_node node[num];
    for(int i = 0; i < num; i++)
    {
        node[i].self = info[i];
        node[i].parents = 0;
        node[i].child1 = 0;
        node[i].child2 = 0;
    }
    node[0].parents = -1;
    for(int i = 0; i <edges.size(); i++)
    {
        int parent = edges[i][0];
        int child = edges[i][1];
        if (node[parent].child1 == 0)
            node[parent].child1 = child;
        else
            node[parent].child2 = child;
        node[child].parents = parent;
    }
    
    greedy(node, 0, 0, node[0].child1, &answer, 0);
    return answer;
}

int main()
{
	vector<int> info = {0,0,1,1,1,0,1,0,1,0,1,1};
	vector<vector<int>> edges = {{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}};
	int a = solution(info, edges);
	cout << "sssssssssss: " << a <<endl;
}