import java.util.ArrayList;

public class prob
{

    public int getNum(String str,ArrayList<Integer> charToNum)
    {
        int val=0;
        for(int j=0;j<str.length();j++)
        {
            Integer digit=charToNum[str[j]-'A'];
            val=val*10+digit;
        }
        return val;
    }

    void helper(int i,ArrayList<Character> &distinctChar,ArrayList<bool> &isUsed,int distinctCharCnt,ArrayList<int> &charToNum,String &operand1,String &operand2,String &res,bool &found,ArrayList<int> &resCharToNum)
    {
        if(found)
            return;

        if(i==distinctCharCnt)
        {
            // calculate the expression
            int oper1,oper2,ans;
            oper1=getNum(operand1,charToNum);
            oper2=getNum(operand2,charToNum);
            ans=getNum(res,charToNum);

            if(oper1+oper2==ans)
            {
                found=true; 
                resCharToNum=charToNum;
            }
            return;
        }

        char curChar=distinctChar[i];

        for(int newNum=0;newNum<=9;newNum++)
        {
            if(isUsed[newNum])
                continue;

            isUsed[newNum]=1;
            charToNum[curChar-'A']=newNum;
            helper(i+1,distinctChar,isUsed,distinctCharCnt,charToNum,operand1,operand2,res,found,resCharToNum);
            isUsed[newNum]=0;
        }
    }

    
	public static void main(String[] args) {
		String expression;
        cin>>expression;
        int i=0,sz=expression.size();
        String operand1,operand2,res;

        String temp;
        ArrayList<bool> isPresent(26,0);
        ArrayList<char> distinctChar;

        ArrayList<int> charToNum(26),resCharToNum(26);
        ArrayList<bool> isUsed(10,0);

        bool isNPresent=false;

        for(i=0;i<sz;i++)
        {
            if(expression[i]=='+')
            {
                operand1=temp;
                temp.clear();
            }
            else if(expression[i]=='=')
            {
                operand2=temp;
                temp.clear();
            }
            else
            {
                if(expression[i]=='N')
                {
                    isNPresent=true;
                    charToNum['N'-'A']=6;
                    isUsed[6]=1;
                }
                else if(isPresent[expression[i]-'A']==0)
                    distinctChar.push_back(expression[i]);
                isPresent[expression[i]-'A']=1;
                temp+=expression[i];
            }
        }

        res=temp;

        if(distinctChar.size()+isNPresent>10)
        {
            cout<<"No Solution"<<endl;
            return;
        }

        bool found=false;

        helper(0,distinctChar,isUsed,distinctChar.size(),charToNum,operand1,operand2,res,found,resCharToNum);

        int oper1=0,oper2=0,ans=0;

        if(!found)
        {
            cout<<"No Solution"<<endl;
            return;
        }
        oper1=getNum(operand1,resCharToNum);
        oper2=getNum(operand2,resCharToNum);
        ans=getNum(res,resCharToNum);

        cout<<oper1<<"+"<<oper2<<"="<<ans<<endl;
	}
}
