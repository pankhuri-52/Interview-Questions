// { Driver Code Starts
import java.util.*;
class SDN{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0){
			int n=sc.nextInt();
			GfG g=new GfG();
			System.out.println(g.getSmallestDivNum(n));
		}
	}
}// } Driver Code Ends


/*Complete the Given Function*/
class GfG{
    static long gcd(long a,long b){
        if(a%b!=0)
          return gcd(b,a%b);
        else
          return b;
    }
	public static long getSmallestDivNum(int n){
       long ans=1;
       for(int i=1;i<=n;i++){
           ans=(ans*i)/gcd(ans,i);
       }
       return ans;
  }
}
