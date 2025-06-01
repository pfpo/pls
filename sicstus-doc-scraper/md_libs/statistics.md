


Next: [lib\-structs](lib_002dstructs.html), Previous: [lib\-sockets](lib_002dsockets.html), Up: [The Prolog Library](The-Prolog-Library.html)   \[[Contents](index.html#SEC_Contents "Table of contents")]\[[Index](Predicate-Index.html "Index")]





---


### 10\.43 Statistics Functions—`library(statistics)`


This library module provides commonly used sample and population statistics functions.
In this module, a Sample is simply a proper list of numbers, normally floating\-point;
Weight is a proper list of numbers and should be of the same length as Sample.



**Please note:** These functions are plain textbook algorithms and we make no claims
about numerical stability, avoiding loss of precision, etc.



Exported predicates:



`min(+Sample, -Value)`



is true when Value is the smallest element of Sample.



`max(+Sample, -Value)`



is true when Value is the largest element of Sample.



`min_max(+Sample, -Min, -Max)`



is true when Min (Max) is the smallest (largest) element of Sample.



`range(+Sample, -Value)`



is true when Value is the difference between the largest and smallest elements of Sample.



`mode(+Sample, -Values)`



is true when Values is the most frequently occurring value(s) in Sample. 
If there is a unique value with maximum frequency, this value is returned as the only element of Values. 
Otherwise, Values contains the maximum frequency elements in increasing order.
This predicate does not make much sense if the sample is continuous.



`mean(+Sample, -Value)`
`arithmetic_mean(+Sample, -Value)`





is true when Value is the arithmetic mean of Sample.



`weighted_mean(+Weight, +Sample, -Value)`



is true when Value is the arithmetic mean of Sample weighted by Weight.



`geometric_mean(+Sample, -Value)`



is true when Value is the geometric mean of Sample.



`harmonic_mean(+Sample, -Value)`



is true when Value is the harmonic mean of Sample.



`central_moment(K, +Sample, -Value)`



is true when Value is the K\-th central moment of Sample.
Also known as the K\-th central moment about the mean.
K should be positive integer.



`skewness(+Sample, -Value)`



is true when Value is the skewness of Sample.
This is a measure of the asymmetry of its distribution.
A sample with negative skew is said to be *left\-skewed*.
Most of its mass is on the right of the distribution, with the tail on the left.
Vice versa for positive skew.
A sample’s skewness is undefined if its variance is zero.



`kurtosis(+Sample, -Value)`



is true when Value is the excess kurtosis of Sample.
This is a measure of the peakedness of its distribution.
A high kurtosis indicates that most of the sample’s variance is 
due to infrequent severe deviations, rather than frequent modest deviations.
A sample’s excess kurtosis is undefined if its variance is zero.
In this implementation, the kurtosis of the normal distribution is 0\.



`ml_variance(+Sample, -Value)`
`population_variance(+Sample, -Value)`





is true when Value is the maximum likelihood estimate of the variance of Sample.
Also known as the population variance, where the denominator is the length of Sample.



`sample_variance(+Sample, -Value)`
`unbiased_variance(+Sample, -Value)`





is true when Value is the unbiased estimate of the variance of Sample.
Also known as the sample variance, where the denominator is the length of Sample minus one.



`weighted_variance(+Weight, +Sample, -Value)`



is true when Value is the weighted (biased) estimate of the variance of Sample.



`ml_standard_deviation(+Sample, -Value)`
`population_standard_deviation(+Sample, -Value)`





is true when Value is the maximum likelihood estimate of the standard deviation of Sample.
Also known as the population standard deviation, where the denominator is the length of Sample.
Equals the square root of the population variance.



`sample_standard_deviation(+Sample, -Value)`
`unbiased_standard_deviation(+Sample, -Value)`





is true when Value is the unbiased estimate of the standard deviation of Sample.
Also known as the sample standard deviation, where the denominator is the length of Sample minus one.
Equals the square root of the sample variance.



`weighted_standard_deviation(+Weight, +Sample, -Value)`



is true when Value is the weighted (biased) estimate of the standard deviation of Sample.
Equals the square root of the weighted (biased) variance.



`covariance(+Sample1, +Sample2, -Value)`



is true when Value is the covariance of Sample1 and Sample2.



`correlation(+Sample1, +Sample2, -Value)`



is true when Value is the correlation of Sample1 and Sample2.
If there is no variance in Sample1 or in Sample2, an error is raised.



`median(+Sample, -Value)`



is true when Value is the median of Sample, that is,
the value separating the higher half of the sample from the lower half.
If there are an even number of observations, then the median is defined to be the smaller middle value.
Same as the 0\.5\-fractile of Sample.



`fractile(P, +Sample, -Value)`



is true when Value is the P\-fractile of Sample, that is,
the smallest value in the sample such that the fraction P of the sample is less than or equal to that value.
P should be a number in (0\.0,1\.0].



`normalize(+Sample, -Normalized)`



is true when Normalized is the normalized Sample, so that
Normalized has a mean of 0 and a population standard deviation of 1\.






---



[|  |
| --- |](https://sicstus.sics.se/)


* [User's Manual](index.html#Top)


---

* [Table of Contents](index.html#TOC)* [Next](lib_002dstructs.html)* [Previous](lib_002dsockets.html)* [Up](The-Prolog-Library.html)





---


[Send feedback on this subject.](mailto:sicstus-support@ri.se?subject=Documentation%20feedback%20on%20html/sicstus/lib_002dstatistics.html&body=Feedback%20on%20documentation%20node%20html/sicstus/lib_002dstatistics.html%20in%20User's%20Manual.)
