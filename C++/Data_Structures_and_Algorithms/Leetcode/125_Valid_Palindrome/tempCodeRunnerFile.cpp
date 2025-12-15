bool isPalindrome(string &s)
{
    string tempstr;
    for (int i = 0; i < s.length(); i++)
    {
        int a = int(s[i]);
        if ((a < 65 && a > 90) && (a < 97 && a > 122))
        {
            continue;
        } // Filter out everything except letters
        else if (a > 65 && a < 90)
        {
            tempstr.push_back(char(a + 32));
        } // convert all capital to small
        else
        {
            tempstr.push_back(char(a));
        }
    } // tempstr updated
    int startind = 0, endind = tempstr.length() - 1;
    while (startind < endind)
    {
        if (tempstr[startind] != tempstr[endind])
        {
            return false;
        }
        startind++;
        endind--;
    }
    return true;
}