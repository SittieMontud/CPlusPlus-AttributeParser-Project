#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n, q;
    cin >> n >> q;
    cin.ignore();
    string line, mkey, mvalue;
    string loc="";
    size_t dmp;
    vector<string> tags;
    map<string,string> data;

    //HRML lines 
    for (int i=0;i<n;i++) {
        getline(cin, line);

        //get the tag name
        if (line.find(" ")!=-1) dmp=line.find(" ");//first space
        else dmp=line.find(">"); //tag with no attributes
        if (line[1]=='/') tags.pop_back();
        else {
            tags.push_back(line.substr(1,dmp-1));
            //cout << "tag name: " << line.substr(1,dmp) << endl;
            line.erase(line.begin(),line.begin()+dmp+1);
        }
        //cout << line <<endl;

        while(line.find(" ")!=-1) {
            //get attribute
            dmp=line.find(" ");//second space
            mkey=line.substr(0,dmp);
            for (int i=0;i<tags.size();i++){
                if (i==0) loc=loc+tags[i];
                else loc = loc + "." + tags[i];
            }
            mkey=loc+"~"+mkey;
            //cout << "key: " << mkey << endl;
            line.erase(line.begin(),line.begin()+dmp+4);
            //cout << line << endl;

            //get value
            dmp=line.find("\"");//get end quote
            mvalue=line.substr(0,dmp);
            //cout<< "value: " << mvalue<<endl;
            line.erase(line.begin(),line.begin()+dmp+2);
            //cout << line << endl;

            //store to map and vector map
            data.insert(make_pair(mkey,mvalue));

            //reset
            loc.clear();
        }
        
    }

    string query;
    vector<string> query_vector;

    //Query lines
    //cout << "q: " << q;
    for (int i=0;i<q;i++) { //query lines 
        cin >> query;
        query_vector.push_back(query);
    }

    //Check query
    for (int i=0;i<q;i++) {
        if (data.count(query_vector[i])) { //key exists
                cout << data[query_vector[i]] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }
    
    return 0;
}
