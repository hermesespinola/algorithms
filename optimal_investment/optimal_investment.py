def optimal_investment(d, n, r, f1, f2):
    """
    Optimal investment strategy at the end of 10 years with d dollars, n number
    of investments, r_i,j return rates in each year and a fee of f1 if you
    decide to leave your money in the same set of investments or a fee of f2 if
    you decide to switch your money to a different set of investments.
    """

    I = [0] * 11    # I[i] tells which investment should be made in year i
    R = [0] * 11    # R[i] gives the total return on the investment in years i through 10
    for k in xrange(9, -1, -1):    # for each year
        q = 0   # the best investment so far

        for i in xrange(n): # see all posible investments
            if r[i][k] > r[q][k]:   # there's a better investment
                q = i

        # decide if stay or switch investment
        stay_rev = d * r[I[k+1]][k] - f1
        switch_rev =  d * r[q][k] - f2
        if stay_rev > switch_rev:
            R[k] = R[k + 1] + stay_rev
            I[k] = I[k + 1]
        else:
            R[k] = R[k + 1] + switch_rev
            I[k] = q
    return I, R


print optimal_investment(10000, 2, [[1.5]*10, [2]*10], 0, 0)
