// package THE_BUG;

import java.util.Arrays;
import java.util.Scanner;

class Subsets{
    long countTriplets(long arr[], int n,int sum)
    {
        Arrays.sort(arr);
        int i=0;
        int count=0;
        while(i<(n-1))
        {
            int j = i+1;
            int k=i+2;
            while(j<n && k<n)
            {
                if( (arr[i]+arr[j]+arr[k])<sum)
                {
                    count++;
                    k++;
                }
                else{
                    j++;
                }
            }
            i++;
        }
        return count;
    }
}
public class subsets_Bug {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int sum = s.nextInt();
        long []arr = new long[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = s.nextLong();
        }
        Subsets obj = new Subsets();
        System.out.println(obj.countTriplets(arr,n,sum));

    }
}

// Test Case:
//     18
//     86
//            30 8 23 6 10 9 31 7 19 20 1 33 21 27 28 3 25 26
//     correct output:
//     796
// Test Case:
//        5
//        12
//        5 1 3 4 7
//         correct output:
//         4
// Test Case:
//       5 3
//      -3 0 1 -2 4
        //correct output:
        //8