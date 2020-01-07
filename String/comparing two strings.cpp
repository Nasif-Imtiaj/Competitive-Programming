bool cmp(string s1,string s2)
{
    if(s1.length()<s2.length())
        return 1;
    else if(s1.length()==s2.length())
    {
        if(lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end()))
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
