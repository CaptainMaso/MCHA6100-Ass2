function lse = logSumExp(x)

xstar = max(x, [], 2);
lse = (xstar + log(sum(exp(x-xstar),2)));