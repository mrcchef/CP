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
    ll available;
    ll availTime;
    person(){

    }
    person(ll id,string name,vector<pair<ll,ll>> &sk){
        this->id = id;
        this->name = name;
        this->skill = sk;
        available = 0;
        availTime=0;
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

double w1,w2;

bool compare(project &a,project &b){
    
    // if(a.duration==b.duration){
    //     return a.score > b.score;
    // }
    double mx=1e7;
    double a1Score=mx/a.score;
    double b1Score=mx/b.score;

    // return a.role.size()<b.role.size();
    return w1*a.role.size() + w2*a1Score< w1*b.role.size()+w2*b1Score;
}

// score -> 1e5/score

// w1,w2 : w1*a.duration + w2*a.score 

ll finalAns=0;
vector<project> finalProject; 
ll finalCnt=0;

ll simulate(ll cnt,vector<project> Project,vector<person> Person)
{
    ll score=0;
    ll curTime=0;

    for(ll i=0;i<Project.size();i++)
    {
        ll stTime=0;
        project curProj = Project[i];
        if(curProj.contributors.empty()){
            continue;
        }

        for(auto &personId:curProj.contributors)
        {
            stTime=max(stTime,Person[personId].availTime);
        }

        ll endTime=stTime+curProj.duration;

        ll contri=curProj.score;
        ll redu=min(curProj.score,endTime-curProj.best_before);
        if(endTime>=curProj.best_before)
        {
            contri-=redu;
        }

        for(auto &personId:curProj.contributors)
        {
            Person[personId].availTime=endTime;
        }

        score+=contri;
    }

    if(finalAns<score)
    {
        finalProject=Project;
        finalCnt=cnt;
        finalAns=max(finalAns,score);
    }

    // debug(score);
}

void solve(vector<project> Project,ll proj,vector<set<pair<ll,ll>>> dp,vector<person> Person)
{
    sort(Project.begin(),Project.end(),compare);
    ll ans = proj;

    for(int i=0;i<proj;i++){
        project& curProj = Project[i];
        int roleSize = curProj.role.size();
        ll skillId,level;
        ll firstAvailable = INT_MIN;
        for(int j=0;j<roleSize;j++){
            tie(skillId,level)  = curProj.role[j];
            // as of now only considering contribute with lvl >= level
            auto it = dp[skillId].lower_bound({level,-1});
            ll takenId = -1;
            ll fastTime = INT_MAX;
            while(it!=dp[skillId].end()){
                ll personId = (*it).second;
                // as of now not considering person availability
                // check if person is already assigned to this project or not
                if(Person[personId].assigned.find(curProj.id)==Person[personId].assigned.end()){
                    // curProj.contributors.push_back(personId);
                    // Person[personId].assigned.insert(curProj.id);
                    if(Person[personId].available < fastTime){
                        takenId = personId;
                        fastTime = Person[personId].available;
                    }
                    // break;
                }
                it++;
            }
            //
            if(takenId!=-1){
                firstAvailable = maxv(firstAvailable,Person[takenId].available);
                curProj.contributors.push_back(takenId);
                Person[takenId].assigned.insert(curProj.id);
            }else{
                // we will gonna to clear person assigned set
                ans--;
                curProj.contributors.clear();
                break;
            }
        }
        if(curProj.contributors.size()>0){
            // we have taken this project;
            int kk =0;
            for(auto &x:curProj.contributors){
                // x-> contributor
                ll curSkillId = curProj.role[kk].first;

                // to update the contributor skill
                for(int jj=0;Person[x].skill.size();jj++){
                    if(Person[x].skill[jj].first==curSkillId){
                        ll curLevel = Person[x].skill[jj].second;
                        if(curLevel==curProj.role[kk].second){
                            dp[curSkillId].erase({curLevel,x});
                            dp[curSkillId].insert({curLevel+1,x});
                            Person[x].skill[jj].second++;
                        }
                        break;
                    }
                }
                kk++;
                // dp[i] = {{lvl,personId},{}}
                Person[x].available = firstAvailable + curProj.duration;
            }
        }
    }

    simulate(ans,Project,Person);
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
    ll cont,proj;
    cin>>cont>>proj;
    vector<person> Person;
    vector<project> Project;

    // vec[i] -> {{lvl,person_id},{}}
    vector<set<pair<ll,ll>>> dp(1000);

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

    ll i=5;
    ll total=1000;
    uniform_real_distribution<double> unif(0, 1);
    std::mt19937_64 rng;
    for(i=0;i<total;i++)
    {
        w1 = unif(rng);
        // debug(currentRandomNumber);
        // w1= ((double) rand() / (RAND_MAX)) ;
        w2=1-w1;
        // debug(w1);
        // debug(w2);
        // w1=10*i+1;
        // w2=(10-i);
        solve(Project,proj,dp,Person);
    }
    
    debug(finalAns);
    cout<<finalCnt;nl;
    for(int i=0;i<proj;i++){
        project curProj = finalProject[i];
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
