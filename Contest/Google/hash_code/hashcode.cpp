// Jai Shree Ram⛳⛳⛳
// Keshav Agarwal, Codechef_handle = agarwal_keshav; codeforces_handle = agarwal_keshav
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define nl cout<<"\n";
#define fix(f,n) cout<<fixed<<setprecision(n)<<f
const int mod = 1e9+7;
template<typename ...T>
void debug(T&&... args){ ((cerr << args << " "), ...);cerr<<"\n";}
ll gcd(ll a,ll b){ return a?gcd(b%a,a):b; }
ll minv(ll a,ll b){ return a<b?a:b;}
ll maxv(ll a,ll b){ return a>b?a:b;}
void swapv(ll &a,ll &b){a=a+b;b=a-b;a=a-b;}
ll power(ll a, ll b, ll m=mod){
    if(a==0 || b==1) return a;
    if(b==0) return 1;ll ans=1;
    while(b>=1){ if(b&1){b--;ans = (ans*a) % m;}a = (a*a)% m;b = b>>1;}return ans;
}
ll logv(ll x){ll ans =-1;while(x){x = x>>1;ans++;}return ans;}
ll inv(ll a,ll m){return power(a,m-2,m);}



struct person{
    ll id;
    string name;
    vector<pair<ll,ll>> skill;
    // skill[i] = {skill_id,skill_level}
    unordered_set<ll> assigned;
    person(){

    }
    person(ll id,string name,vector<pair<ll,ll>> &sk){
        this->id = id;
        this->name = name;
        this->skill = sk;
    }
};

struct project{
    string name;
    ll id;
    ll duration,score,best_before;
    vector<pair<ll,ll>> role;
    // role[i] = {skill_id,skill_level}
    vector<ll> contributors;
    project(){

    }
    project(ll id,string name,ll duration,ll score,ll best_before,vector<pair<ll,ll>> &vec){
        this->name  =name;
        this->id = id;
        this->duration = duration;
        this->score = score;
        this->best_before = best_before;
        role = vec;
    }
};

bool compare(project &a,project &b){
    return a.best_before > b.best_before;
}



ll simulate(ll cnt,vector<project> &Project)
{
    ll score=0;



    for(ll i=0;i<Project.size();i++)
    {
        project curProj = Project[i];
        if(curProj.contributors.empty()){
            continue;
        }



    }

}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr); 
    #endif 
    
    unordered_map<string,ll> skillMap,nameMap;
    ll skillCount = 0;
    ll cont;
    ll proj;
    vector<person> Person;
    vector<project> Project;
    cin>>cont;
    cin>>proj;

    // vec[i] -> {{lvl,person_id},{}}
    vector<set<pair<ll,ll>>> dp(2000);

    for(int i=0;i<cont;i++){
        string name;
        cin>>name;
        ll num;cin>>num;
        nameMap[name] = i;
        vector<pair<ll,ll>> vec;
        while(num--){
            string skillName;
            ll lvl;
            cin>>skillName>>lvl;
            if(skillMap.find(skillName)==skillMap.end()){
                skillMap[skillName] = skillCount++;
            }
            ll skillId = skillMap[skillName];
            vec.push_back({skillId,lvl});
            dp[skillId].insert({lvl,i});
        }
        Person.push_back(person(i,name,vec));
    }

    for(int i=0;i<proj;i++){
        string name;
        ll duration,score,best,num;
        cin>>name>>duration>>score>>best>>num;
        vector<pair<ll,ll>> vec;
        while(num--){
            string skill;
            ll lvl;
            cin>>skill>>lvl;
            if(skillMap.find(skill)==skillMap.end()){
                skillMap[skill] = skillCount++;
            }
            vec.push_back({skillMap[skill],lvl});
        }
        Project.push_back(project(i,name,duration,score,best,vec));
    }


    sort(Project.begin(),Project.end(),compare);
    ll ans = proj;

    for(int i=0;i<proj;i++){
        project& curProj = Project[i];
        int roleSize = curProj.role.size();
        ll skillId,level;
        for(int j=0;j<roleSize;j++){
            tie(skillId,level)  = curProj.role[j];
            // as of now only considering contribute with lvl >= level
            auto it = dp[skillId].lower_bound({level,-1});
            bool flag = false;
            while(it!=dp[skillId].end()){
                ll personId = (*it).second;
                // as of now not considering person availability

                // check if person is already assigned to this project or not
                if(Person[personId].assigned.find(curProj.id)==Person[personId].assigned.end()){
                    curProj.contributors.push_back(personId);
                    Person[personId].assigned.insert(curProj.id);
                    flag = true;
                    break;
                }
                it++;
            
                
            }
            if(flag){
                ;
            }else{
                // we will gonna to clear person assigned set
                ans--;
                curProj.contributors.clear();
                break;
            }
        }
    }
    cout<<ans;nl;
    for(int i=0;i<proj;i++){
        project curProj = Project[i];
        if(curProj.contributors.size()>0){
            cout<<curProj.name;nl;
            for(auto &x:curProj.contributors){
                cout<<Person[x].name<<" ";
            }
            nl;
        }
    }

    return 0;
}
