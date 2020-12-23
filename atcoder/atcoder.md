# Note of Atcoder

## 2020822
### Q3 moving xy plane
    - Breadth first search    
    - not search by matrix order 
    - should use 2 queue
    - one is for check next, the other is for jump
### Q4 Bonber
    - think as number theory
    - consider only #{row candidate} * #{col candidate} < M or not.
    - use Dirichlet box principle, if not above case, we always can find the space.

## 20200913
    - mod p = 1e9+7
      - if  negaive -> add p
      - p is prime -> z/pz is field
      - nCr algorithm for p
    - manhattan distance
      - max{|xi-xj|+|yi-yj|, i,j} 
      - = max{max{|vi-vj|, |wi-wj|}, i,j}, where vi = xi+yi, wi=xi-yi

## 20200919
### LIS : longest increase sequence
数列{a_i}と整数 K が与えられます。
以下の条件を満たす数列 B の長さとして考えられる最大値を出力してください。
- B は A の (連続とは限らない) 部分列である。
- どの B の隣り合う要素の差の絶対値も K 以下である。

- solution
  - Step1. consider DP
    - dp[i][j] = {a_iまでの列で、a_i=jの時、条件を満たす最大の列の長さ}
    - dp[i+1][a_i+1] = max(a[i][a_i-K] ~ a[i][a_i+K])
  - Step2. segTree + 配列使いまわし
    - for i :
      - dp[i+1] <- max(a[i]-K ~ )dp[j]
      - segTree.prod(a[i]-K, a[i][a_i]+K)
      - segTree.set(a[i])

