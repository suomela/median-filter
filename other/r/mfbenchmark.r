args=(commandArgs(TRUE))
if (length(args)==0) {
    seed <- 1
} else {
    for(i in 1:length(args)){
        eval(parse(text=args[[i]]))
    }
}

test <- function(h, b, alg) {
    set.seed(seed)
    k <- 2*h+1
    n <- k*b
    x <- sample(2**32, n)
    e <- system.time(runmed(x, k, "keep", alg))["elapsed"]
    cat(sprintf('R%s\t%d\t%d\tr-large\t%d\t%.3f\n', alg, h, b, seed, e), sep="")
    flush.console()
}

test1 <- function(h, b) {
    test(h, b, "Turlach")
}

test2 <- function(h, b) {
    test(h, b, "Stuetzle")
}


test1(1, 10000)
test1(10, 1000)
test1(100, 100)
test1(1000, 10)
test1(1, 100000)
test1(10, 10000)
test1(100, 1000)
test1(1000, 100)
test1(10000, 10)
test1(1, 1000000)
test1(10, 100000)
test1(100, 10000)
test1(1000, 1000)
test1(10000, 100)
test1(100000, 10)
test1(1, 10000000)
test1(10, 1000000)
test1(100, 100000)
test1(1000, 10000)
test1(10000, 1000)
test1(100000, 100)
test1(1000000, 10)

test2(1, 10000)
test2(10, 1000)
test2(100, 100)
test2(1000, 10)
test2(1, 100000)
test2(10, 10000)
test2(100, 1000)
test2(1000, 100)
test2(10000, 10)
