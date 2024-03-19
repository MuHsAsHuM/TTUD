#include <bits/stdc++.h> 
using namespace std;

bool checkInvalidNumber(string number){
    if(number.length() != 10) return false;
    else{
        for( auto x : number ){
            if(!isdigit(x)) return false;
        }
    }
    return true;
}

int call_time_in_second(string s2, string s1){
    int hour = (s1[0] - s2[0])*10 + s1[1] - s2[1];
    int minute = (s1[3] - s2[3])*10 + s1[4] - s2[4];
    int second = (s1[6] - s2[6])*10 + s1[7] - s2[7];
    return hour*3600 + minute*60 + second;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string call;
    string from_number;
    string to_number;
    string date;
    string from_time;
    string to_time;
    
    int number_total_calls = 0;
    int correct_number = 1;
    map<string, int> call_total;
    map<string, int> call_time;
    
    while(1){
        cin>>call;
        if(call == "#") break;
        cin>>from_number>>to_number>>date>>from_time>>to_time;
        if( !checkInvalidNumber(from_number) || !checkInvalidNumber(to_number) ){
            correct_number = 0;
        }
        call_total[from_number]++;
        call_time[from_number] += call_time_in_second(from_time,to_time);
        number_total_calls++;
    }
    
    while(1){
        string cmd;
        cin>>cmd;
        if(cmd == "#") break;
        if(cmd == "?check_phone_number"){
            cout<<correct_number<<endl;
        }
        if(cmd == "?number_total_calls"){
            cout<<number_total_calls<<endl;
        }
        if(cmd == "?number_calls_from"){
            string number;
            cin>>number;
            cout<<call_total[number]<<endl;
        }
        if(cmd == "?count_time_calls_from"){
            string number;
            cin>>number;
            cout<<call_time[number]<<endl;
        }
    }
    
    return 0;
}
