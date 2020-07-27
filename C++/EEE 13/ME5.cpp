#include <bits/stdc++.h>

using namespace std;
int i;
int counter = 0;
vector<string> arr({"abcde", "abcde", "abcde", "abcde", "abcde", "abcde", "abcde"});

void f(int index, string build){
    if(index == i){
        if(counter > 0)
        {
            cout << build << endl;
            counter = 0;
        }
        return;
    }

    for(int j = 0; j<arr[index].size(); j++){
        string next_build = build;
        next_build.push_back(arr[index][j]);
        if (!(((next_build[index-1] == 'a') ||(next_build[index-1] == 'e')) && ((arr[index][j] == 'a') ||(arr[index][j] == 'e')))){
            for(int a = 0; a < arr[index].size(); a++){
                if((next_build[a-1] == 'a') ||(next_build[a-1] == 'e')){
                    counter++;
                }
            }
            f(index+1, next_build);
        }
    }
}

int main(){
    cin >> i;
    f(0, "");
}
