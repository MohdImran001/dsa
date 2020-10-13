#include <bits/stdc++.h>
#define ll long long int
#define v vector
#define b begin
#define e end

using namespace std;

class Trie
{
public:
    Trie *left;
    Trie *right;
};

void insert(Trie *&root, int val)
{
    Trie *curr = root;

    for (int i = 31; i >= 0; --i)
    {
        int b = (val >> i) & 1;

        if (b == 0)
        {
            if (!curr->left)
            {
                curr->left = new Trie();
            }
            curr = curr->left;
        }
        else
        {
            if (!curr->right)
            {
                curr->right = new Trie();
            }
            curr = curr->right;
        }
    }
}

int findMaxXor(Trie *head, v<int> &arr, int n)
{
    int max_xor = INT_MIN;

    for (int i = 0; i < n; ++i)
    {
        int val = arr[i];
        Trie *curr = head;
        int curr_xor = 0;

        for (int j = 31; j >= 0; --j)
        {
            int b = (val >> j) & 1;

            if (b == 0)
            {
                if (curr->right)
                {
                    curr_xor += pow(2, j);
                    curr->right;
                }
                else
                {
                    curr->left;
                }
            }
            else
            {
                if (curr->left)
                {
                    curr_xor += pow(2, j);
                    curr->left;
                }
                else
                {
                    curr->left;
                }
            }
        }

        max_xor = max(max_xor, curr_xor);
    }

    return max_xor;
}

int main()
{
    int n;
    cin >> n;

    Trie *head = new Trie();

    v<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        insert(head, arr[i]);
    }

    cout << findMaxXor(head, arr, n) << endl;
    return 0;
}
