#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, X, Y, Z;

    cin >> N >> X >> Y >> Z;

    set<int> admitted;
    priority_queue<pair<int, int>> math_scores;
    priority_queue<pair<int, int>> eng_scores;
    priority_queue<pair<int, int>> total_scores_q;
    int total_scores[1000];

    for (int i = 0; i < N; i++)
    {
        int score;
        cin >> score;
        math_scores.push(make_pair(score, -i));
        total_scores[i] = score;
    }

    for (int i = 0; i < X; i++)
    {
        admitted.insert(-math_scores.top().second + 1);
        math_scores.pop();
    }

    for (int i = 0; i < N; i++)
    {
        int score;
        cin >> score;
        eng_scores.push(make_pair(score, -i));
        total_scores[i] += score;
    }

    for (int i = 0; i < Y; i++)
    {
        bool founded = false;
        while (not founded)
        {
            if (admitted.find(-eng_scores.top().second + 1) == admitted.end())
            {
                founded = true;
                admitted.insert(-eng_scores.top().second + 1);
            }
            eng_scores.pop();
        }
    }

    for (int i = 0; i < N; i++)
    {
        total_scores_q.push(make_pair(total_scores[i], -i));
    }

    for (int i = 0; i < Z; i++)
    {
        bool founded = false;
        while (not founded)
        {
            if (admitted.find(-total_scores_q.top().second + 1) == admitted.end())
            {
                founded = true;
                admitted.insert(-total_scores_q.top().second + 1);
            }
            total_scores_q.pop();
        }
    }

    for (auto &&i : admitted)
    {
        cout << i << "\n";
    }

    return 0;
}