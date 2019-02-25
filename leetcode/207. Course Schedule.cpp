static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {

    // 有环返回true, 无环为false
    bool dfs(std::vector<std::vector<int>>& graph)
    {
        std::stack<int> stk;
        // 0未访问，1访问过了，-1正在从此结点开始往下DFS
        std::vector<int> visited(graph.size(), 0);
        for (int j = 0; j < graph.size(); ++j)
        {
            if (visited[j] == 0)
            {
                stk.push(j);
                while (!stk.empty())
                {
                    int top = stk.top();
                    visited[top] = -1;
                    int i = 0;
                    for (; i < graph.size(); ++i)
                    {
                        if (visited[i] == 0 && graph[top][i])
                        {
                            stk.push(i);
                            break;
                        }
                        else if (visited[i] == -1 && graph[top][i])
                        {
                            return true;
                        }
                    }
                    if (i == graph.size())
                    {
                        stk.pop();
                        visited[top] = 1;
                    }
                }
            }
        }
        return false;
    }

public:
    bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses, std::vector<int>(numCourses));
        std::vector<int> visited(numCourses, 0);
        for (std::pair<int, int> pair : prerequisites)
        {
            graph[pair.first][pair.second] = 1;
        }
        return !dfs(graph);
    }
};