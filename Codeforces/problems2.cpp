#include<bits/stdc++.h>
using namespace std;

struct task{ // task format
    int taskID;
    string assigneeName;
    string reviewerName;
    string status;
    int estimateInHours;
    bool operator < ( task a){
        return estimateInHours > a.estimateInHours;
    }
    void print(){ // prints task information
     cout << "taskId: "<< taskID << '\n';
     cout << "assigneeName: " << assigneeName <<'\n';
     cout << "reviewerName: " << reviewerName<<'\n';
     cout << "status: " << status << '\n';
     cout << "estimateInHours: " << estimateInHours << '\n';
     cout << '\n';
    }
};

vector<task> reviewerAssignment(vector<task> &tasks, map<string, double> &estimateHours){
    int n = tasks.size();
    sort(tasks.begin(), tasks.end()); // sort based on time takes
    set<pair<double, string >> members;

    for(auto it : estimateHours){
        members.insert({it.second, it.first}); // pick all the person with time
    }

    for(int i = 0; i < n; i++){ // If it is In-review and reviewer null then choose one with small time
        if(tasks[i].reviewerName == "null" && tasks[i].status == "in-review"){
            pair<double, string> p = *members.begin(); 
            members.erase(members.begin());
            tasks[i].reviewerName = p.second;
            p.first += (tasks[i].estimateInHours / 3.0);
            members.insert(p);
        }
    }

    vector<task> res(n);
    for(int i = 0; i < n; i++){// Arrange according to taskID
        res[tasks[i].taskID - 1] = tasks[i];
    }
    return res;
}

int main(){
    int n; cin >> n; //number of task

    vector<task> tasks;
    map<string, double> estimateHours;

    for(int i = 0; i < n; i++){ // inputs
        task t;
        cin >> t.taskID >> t.assigneeName;
        cin >> t.reviewerName >> t.status;
        cin >> t.estimateInHours;

        estimateHours[t.assigneeName]; // which person already assigned for reviewe
        if(t.reviewerName != "null" && t.status == "in-review"){
            estimateHours[t.reviewerName] += (t.estimateInHours / 3.0);
        }
        tasks.push_back(t);
    }


    vector<task> res = reviewerAssignment(tasks, estimateHours);

    for(int i = 0; i < n; i++){ // print output
        res[i].print();
    }
    return 0;
}

