
package THE_BUG; 
import java.util.Arrays; 
import java.util.Scanner; class Subsets{ long countTriplets(long arr[], int n,int sum) { Arrays.sort(arr); int i=0; // int j=1; int count=0; while(i<(n-1)) { int j = i+1; int k=i+2; while(j<n && k<n) { if( (arr[i]+arr[j]+arr[k])<sum) { count++; k++;