package THE_BUG;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

class Edge{
    int destination;
    int weight;
    Edge(int x,int y)
    {
        this.destination=x;
        this.weight=y;
    }
}
class Graph{
    int min = Integer.MAX_VALUE;
    boolean []vis;
    ArrayList<Integer> temp = new ArrayList<>();
    int v;
    LinkedList<Edge>[]adj;
    Graph(int V){
        this.v=V;
        vis = new boolean[V];
        adj = new LinkedList[v];
        for(int i=0;i<v;i++)
        {
            adj[i] = new LinkedList<>();
        }
    }
    void addEdge(int source,int destination,int weight) {
        adj[source].add(new Edge(destination, weight));
//        adj[destination].add(new Edge(source,weight));
    }
    int dfs(int current)
    {
        vis[current] = true;
        if(adj[current].size()==0)
        {
            return current;
        }
        if(adj[current].get(0).weight<min)
            min = adj[current].get(0).weight;
        return dfs(adj[current].get(0).destination);

    }
}
class Solution123{
    ArrayList<ArrayList<Integer>> solve(int n, int p, ArrayList<Integer> a , ArrayList<Integer> b , ArrayList<Integer> d)
    {
        int []out = new int[21];
        int []in = new int[21];
        int []dia = new int[101];
        for(int i=0;i<b.size();i++)
        {
            out[a.get(i)] = b.get(i);
            in[b.get(i)] = a.get(i);
            dia[a.get(i)]=d.get(i);
        }

        Graph obj = new Graph(n+1);
        for (int i=0;i<p;i++)
        {
            obj.addEdge(a.get(i),b.get(i),d.get(i));
        }
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> al;
        for(int i=1;i<=n;i++) {
            if(in[i]==0 && out[i]>0) {
                int ret = obj.dfs(i);
                al = new ArrayList<Integer>();
                al.add(i);
                al.add(ret);
                al.add(obj.min);
                ans.add(al);
                obj.min = Integer.MAX_VALUE;

            }
        }


        return ans;
    }
}

public class Assembly_line {
    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream(new File("C:\\Users\\mrizv\\Downloads\\input.txt.txt")));
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int p = s.nextInt();
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        ArrayList<Integer> d = new ArrayList<>();
        for (int i = 0; i < p; i++) {
            a.add(s.nextInt());
            b.add(s.nextInt());
            d.add(s.nextInt());
        }
        Solution123 obj = new Solution123();
        ArrayList<ArrayList<Integer>> ans;
        ans = obj.solve(n,p,a,b,d);
        System.out.println(ans.size());
        for(int i=0;i<ans.size();i++) {
            System.out.println(ans.get(i));
        }
    }
}
//Test Case:
//17 11
//6 5 2
//4 7 2
//14 16 2
//17 12 4
//3 2 8
//15 13 2
//16 6 8
//5 17 8
//7 1 9
//11 4 9
//12 8 2
//Correct Output:
//4
//3 2 8
//11 1 2
//14 8 2
//15 13 2


//Test case
//for <=n
//14 8
//7 9 10
//10 2 9
//5 8 7
//9 3 1
//3 10 6
//14 5 2
//4 7 2
//1 4 8
//Correct Output
//2
//1 2 1
//14 8 2
