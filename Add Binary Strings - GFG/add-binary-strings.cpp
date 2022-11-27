//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	   int i=A.size()-1, j=B.size()-1;
	   
	   int carry=0;
	   string res;
	   
	   //first step when both strings have characters
	   while(i>=0 && j>=0){
	       int a=A[i]-'0';
	       int b=B[j]-'0';
	       int sum=(a+b+carry);
	       int temp=sum%2;
	       carry=sum/2;
	       
	       char ch=temp+'0';
	       res.push_back(ch);
	       i--;j--;
	   }
	   //one is empty
	   while(j>=0){
	       int b=B[j]-'0';
	       int sum=(b+carry);
	       int temp=sum%2;
	       carry=sum/2;
	       char ch=temp+'0';
	       res.push_back(ch);
	       j--;
	   }
	   while(i>=0){
	       int a=A[i]-'0';
	       int sum=(a+carry);
	       int temp=sum%2;
	       carry=sum/2;
	       char ch=temp+'0';
	       res.push_back(ch);
	       i--;
	   }
	   //at last if carry is 1 then push
	   if(carry) res.push_back(carry+'0');
	   //reverse the string
	   reverse(res.begin(),res.end());
	   //eliminate the leading zeros
	   string ans;
	   int ind=res.find('1'); //string starts from 1
	   ans=res.substr(ind); //so take that substring part
	   return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends