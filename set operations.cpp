#include<bits/stdc++.h>

using namespace std;

string Union_of_strings(string us, string sa, string sb)
{
    int j=0, maxnum=sa.length()+sb.length();

    string temp_uni_string(maxnum, ',');

    for(int i=0; i < maxnum; i++)
    {
        if(sa[i]=='1' || sb[i] == '1')
        {
            temp_uni_string[j++] = us[i];
            temp_uni_string[++j] = ',';
        }
    }

    temp_uni_string.erase(j);

    return temp_uni_string;
}

string Intersection_of_strings(string us, string sa, string sb)
{
    string temp_intersect_string(50, '#');

    int j=0;

    temp_intersect_string[j] = '{';

    for(int i=0; i < sa.length()+ sb.length(); i++)
    {
        if(sa[i]=='1' && sb[i] == '1')
        {
            temp_intersect_string[++j] = us[i];
            temp_intersect_string[++j] = ',';
        }
    }

    temp_intersect_string.erase(j);

    return temp_intersect_string;
}

string Difference_of_strings(string uni_set, string setA_binary, string setB_binary)
{
    string temp_difference_string = uni_set;

    for(int i=0; i <= setB_binary.length(); i++)
    {
        if(setB_binary[i] == '1')
            setB_binary[i] = '0';
        else
            setB_binary[i] = '1';
    }

    int j=0;

    temp_difference_string[j] = '{';

    for(int i=0; i < uni_set.length(); i++)
    {
        if(setA_binary[i]=='1' && setB_binary[i] == '1')
        {
            temp_difference_string[++j] = uni_set[i];
            temp_difference_string[++j] = ',';
        }
    }

    temp_difference_string.erase(j);

    return temp_difference_string;
}

string Compliment_of_strings(string us, string s)
{
    string temp_complement_string(1000, ',');

    int j=0;

    temp_complement_string[j] = '{';

    for(int i=0; i < us.length(); i++)
    {
        if(s[i]=='0')
        {
            temp_complement_string[++j] = us[i];
            temp_complement_string[++j] = ',';
        }
    }

    temp_complement_string.erase(j);

    return temp_complement_string;
}

string binary_coverter(string set_to_convert, string universal_set)
{
    string converted_set = universal_set;

    for(int i=0, j=0; i <= universal_set.length(); i++)
    {
        if(universal_set[i]==set_to_convert[j])
        {
            converted_set[i] = '1';
            j++;
        }
        else
            converted_set[i] = '0';
    }

    return converted_set;
}

int main()
{
    string uni_set,uni_set_binary, setA, setA_binary, setB, setB_binary, union_result, intersection_result, difference_result, compliment_result;

    char m;

    int flag1=0, flag2=0;

    //Taking input of Universal set, set A, set B

    cout << "Input universal set, U: ";

    cin >> uni_set;

    cout << "Input set, A: ";

    cin >> setA;

    cout << "Input set, B: ";

    cin >> setB;

    //Erasing '{' , '}' , ',' from strings

    for(int i=0; i <= uni_set.length(); i++)
    {
        if(uni_set[i] == ',' || uni_set[i] == '{' || uni_set[i] == '}')
            uni_set.erase(i,1);
    }

    if(setA != "{}")
        for(int i=0; i < setA.length(); i++)
            setA.erase(i,1);
    if(setB != "{}")
        for(int i=0; i < setB.length(); i++)
            setB.erase(i,1);

    //Sorting the unordered elements of strings

    sort(uni_set.begin(),uni_set.end());
    sort(setA.begin(),setA.end());
    sort(setB.begin(),setB.end());

    //Initializing size of the binary string

    uni_set_binary = uni_set;
    setA_binary = uni_set;
    setB_binary = uni_set;
    union_result = uni_set;
    intersection_result = uni_set;
    difference_result = uni_set;
    compliment_result = uni_set;

    //Universal_set binary conversion

    for(int uni_counter=0; uni_counter < uni_set.length(); uni_counter++)
        uni_set_binary[uni_counter] = '1';

    //SetA binary conversion

    setA_binary = binary_coverter(setA, uni_set);

    //SetB binary conversion

    setB_binary = binary_coverter(setB, uni_set);

    if(setA[0]=='{' && setA[1]=='}')
        flag1=1;
    else
        for(int i=0; i < setA.length(); i++)
        {
            for(int j=0; j < uni_set.length(); j++)
            {
                if(setA[i]==uni_set[j])
                    flag1 = 1;
            }

            if(flag1==0)
                break;
        }

    if(setB[0]=='{' && setB[1]=='}')
        flag2=1;
    else
        for(int i=0; i < setB.length(); i++)
        {
            for(int j=0; j < uni_set.length(); j++)
            {
                if(setB[i]==uni_set[j])
                    flag2 = 1;
            }

            if(flag2==0)
                break;
        }


    if(flag1==1 && flag2==1)
    {
        cout << endl << "Input a symbol to perform it's corresponding operation:" << endl << endl;
        cout << "u to find Union of set A and set B" << endl;
        cout << "i to find Intersection of set A and set B" << endl;
        cout << "- to find Difference of set A and set B" << endl;
        cout << "a to find compliment of set A" << endl;
        cout << "b to find compliment of set B" << endl;
        cout << endl << "Input e to exit" << endl;

        for(int counter = 0; counter < 1; counter--)
        {
            cout  << endl <<endl << "Operation: ";

            cin >> m;

            if(m == 'e')
                break;

            cout << endl;

            if( m == 'u')
            {
                //Union of set A and set B

                if(setA[0]=='{' && setA[1]=='}' && setB[0]=='{' && setB[1]=='}')
                    union_result="}";
                else
                {
                    union_result = Union_of_strings(uni_set, setA_binary, setB_binary);

                    union_result.replace(union_result.length()-1, 1, "}");
                }

                cout << "\nA U B: " << "{" << union_result << endl;
            }
            else if( m == 'i')
            {
                //Intersection of set A and set B

                if(setA[0]=='{' && setA[1]=='}' || setB[0]=='{' && setB[1]=='}')
                    intersection_result="{";
                else
                {
                    string nothing;

                    nothing.clear();

                    intersection_result = Intersection_of_strings(uni_set, setA_binary, setB_binary);

                    if(intersection_result == nothing)
                        intersection_result="{";
                }


                cout << "\nA I B: " << intersection_result << "}" << endl;
            }
            else if( m == '-')
            {
                //Difference of set A and set B

                if(setA[0]=='{' && setA[1]=='}' && setB[0]=='{' && setB[1]=='}')
                    difference_result="{";
                else
                    difference_result = Difference_of_strings(uni_set, setA_binary, setB_binary);

                cout << "\nA - B: " << difference_result << "}" << endl;
            }
            else if( m == 'a')
            {
                //Compliment of set A

                if(setA[0]=='{' && setA[1]=='}' && setB[0]=='{' && setB[1]=='}')
                    compliment_result="{";
                else
                    compliment_result = Compliment_of_strings(uni_set, setA_binary);

                cout << "\nCompliment of A: " << compliment_result << "}\n";
            }
            else if( m == 'b')
            {
                //Compliment of set B

                if(setA[0]=='{' && setA[1]=='}' && setB[0]=='{' && setB[1]=='}')
                    compliment_result="{";
                else
                    compliment_result = Compliment_of_strings(uni_set, setB_binary);

                cout << "\nCompliment of B: " << compliment_result << "}\n";
            }
            else
                cout << endl << "Invalid Input" << endl;
        }
    }
    else if(flag1==0 && flag2==1)
    {
        cout << endl << "Invalid Input (Set A is not a subset of U)" << endl;
    }
    else if(flag1==1 && flag2==0)
    {
        cout << endl << "Invalid Input (Set B is not a subset of U)" << endl;
    }
    else
        cout << endl << "Invalid Input (Set A and B are not subsets of U)" << endl;

    return 0;
}
