// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, ans = 0, sum = 0;
//     cin >> n;
//     vector<int> arr1(n), arr2(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr2[i];
//     for (int i = 0; i < n; i++)
//         cin >> arr1[i];
//     for (int i = 0; i < n; i++)
//         arr2[i] -= arr1[i];

//     sort(arr2.begin(), arr2.end(), greater<int>());
//     for(int i = 0;i<n;i++)
//     {
//         cout<<arr2[i]<<" ";
//     }
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr2[i];
//         if (sum < 0)
//         {
//             ans += abs(sum);
//             sum = 0;
//         }
//     }
//     cout << ans;
// }

#include <stdio.h>
int main()
{
    int n, i, j, a, sum = 0;
    printf("Enter the no of books");
    scanf("%d", &n);
    int arr_earn[n], arr_cost[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr_earn[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr_cost[i]);
    }
    for (i = 0; i < n; i++)
    {
        arr_earn[i] = arr_earn[i] - arr_cost[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr_cost[j] > arr_cost[i])
            {
                a = arr_cost[i];
                arr_cost[i] = arr_cost[j];
                arr_cost[j] = a;
            }
        }
    }
    // for (i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr_cost[i]);
    // }
    for (i = 0; i < n; i++)
    {
        sum = sum + arr_earn[i];
    }
    if (sum < 0)
    {
        printf("More money required ! amount = %d", sum * -1);
    }
    else
    {
        printf("You earned money ! amount = %d", sum);
    }
    // printf("%d", sum);
    return 0;
}