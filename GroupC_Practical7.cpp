#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int main(){
    map<string,int>state;
    state.insert(pair<string,int> ("Maharashtra",94473653));
    state.insert(pair<string,int>("Uttar Pradesh",103783773));
    state.insert(pair<string,int>("Madhya Pradesh",43783773));
    state.insert(pair<string,int>("Andra Pradesh",83783773));
    state.insert(pair<string,int>("Delhi",102222773));
    state.insert(pair<string,int>("Goa",1037833));
    state.insert(pair<string,int>("Karnataka",43783773));
    state.insert(pair<string,int>("Tamil Nadu",53783773));
    state.insert(pair<string,int>("Gujarat",103113773));
    string search;
    cout<<"Enter the state to be searched: "<<endl;
    cin>>search;
    map<string,int>::iterator it;
    int flag=0;
    for(it=state.begin();it!=state.end();it++){
        if(search==it->first){
            flag++;
            cout<<"The population of the state "<<it->first<<" = "<<it->second<<endl;
        }
    }
    if(flag==0){
        cout<<"state not found"<<endl;
    }
        

    return 0;
}