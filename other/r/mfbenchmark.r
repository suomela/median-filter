test <- function(h, b, seed, alg) {
    set.seed(seed)
    k <- 2*h+1
    n <- k*b
    x <- sample(2**32, n)
    e <- system.time(runmed(x, k, "keep", alg))["elapsed"]
    if (e < 0.01) {
        e <- system.time(for(i in 1:100) runmed(x, k, "keep", alg))["elapsed"] / 100.0
        cat(sprintf('R%s\t%d\t%d\tr-large\t%d\t%.5f\n', alg, h, b, seed, e), sep="")
    } else if (e < 0.1) {
        e <- system.time(for(i in 1:10) runmed(x, k, "keep", alg))["elapsed"] / 10.0
        cat(sprintf('R%s\t%d\t%d\tr-large\t%d\t%.4f\n', alg, h, b, seed, e), sep="")
    } else {
        cat(sprintf('R%s\t%d\t%d\tr-large\t%d\t%.3f\n', alg, h, b, seed, e), sep="")
    }
    flush.console()
}

test1 <- function(h, b, seed) {
    test(h, b, seed, "Turlach")
}

test2 <- function(h, b, seed) {
    test(h, b, seed, "Stuetzle")
}

for (seed in 1:10) {
    test1(1, 10000, seed)
    test1(10, 1000, seed)
    test1(100, 100, seed)
    test1(1000, 10, seed)
    test1(1, 100000, seed)
    test1(10, 10000, seed)
    test1(100, 1000, seed)
    test1(1000, 100, seed)
    test1(10000, 10, seed)
    test1(1, 1000000, seed)
    test1(10, 100000, seed)
    test1(100, 10000, seed)
    test1(1000, 1000, seed)
    test1(10000, 100, seed)
    test1(100000, 10, seed)
    test1(1, 10000000, seed)
    test1(10, 1000000, seed)
    test1(100, 100000, seed)
    test1(1000, 10000, seed)
    test1(10000, 1000, seed)
    test1(100000, 100, seed)
    test1(1000000, 10, seed)

    test2(1, 10000, seed)
    test2(10, 1000, seed)
    test2(100, 100, seed)
    test2(1000, 10, seed)
    test2(1, 100000, seed)
    test2(10, 10000, seed)
    test2(100, 1000, seed)
    test2(1000, 100, seed)
    test2(10000, 10, seed)
}