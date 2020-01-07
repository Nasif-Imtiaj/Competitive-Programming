string GetSuffix(int n)
{
    n = n % 100;
    if (n > 10 && n < 20)
        return "th";
    else if (n % 10 == 1)
        return "st";
    else if (n % 10 == 2)
        return "nd";
    else if (n % 10 == 3)
        return "rd";
    else
        return "th";
}
