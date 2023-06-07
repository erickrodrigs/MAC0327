/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int calculate_min_time(vector<int> positions, int l) {
    int middle = (l / 2);
    int nearest_middle_elem = 0;
    int nearest_middle_diff = 2147483647;
    
    for (int i = 0; i < (int) positions.size(); i++) {
        int diff = abs(positions[i] - middle);
        
        if (diff < nearest_middle_diff) {
            nearest_middle_diff = diff;
            nearest_middle_elem = positions[i];
        }
    }
    
    return min(nearest_middle_elem, l - nearest_middle_elem);
}

int calculate_max_time(vector<int> positions, int l) {
    int min_elem = *min_element(positions.begin(), positions.end());
    int max_elem = *max_element(positions.begin(), positions.end());
    int max_time_1 = max(min_elem, l - min_elem);
    int max_time_2 = max(max_elem, l - max_elem);
    
    return max(max_time_1, max_time_2);
}

int main()
{
    int t;
    
    cin >> t;
    
    while (t > 0) {
        int l, n, max_time, min_time;
        vector<int> positions;
        
        cin >> l >> n;
        
        for (int i = 0; i < n; i++) {
            int pos;
            cin >> pos;
            positions.push_back(pos);
        }
        
        min_time = calculate_min_time(positions, l);
        max_time = calculate_max_time(positions, l);
        
        cout << min_time << " " << max_time << endl;
        
        t -= 1;
    }

    return 0;
}
