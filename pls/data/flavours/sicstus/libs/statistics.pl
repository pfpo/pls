:- module(statistics,[min/2,max/2,min_max/3,
range/2,mode/2,mean/2,
arithmetic_mean/2,weighted_mean/3,geometric_mean/2,
harmonic_mean/2,central_moment/3,skewness/2,
kurtosis/2,ml_variance/2,population_variance/2,
sample_variance/2,unbiased_variance/2,weighted_variance/3,
ml_standard_deviation/2,population_standard_deviation/2,sample_standard_deviation/2,
unbiased_standard_deviation/2,weighted_standard_deviation/3,covariance/3,
correlation/3,median/2,fractile/3,normalize/2
]).
%! min(+Sample, -Value)
%
% is true when Value is the smallest element of Sample.
%
% @param Sample *list of number*
% @param Value *number*

%! max(+Sample, -Value)
%
% is true when Value is the largest element of Sample.
%
% @param Sample *list of number*
% @param Value *number*

%! min_max(+Sample, -Min, -Max)
%
% is true when Min (Max) is the smallest (largest) element of Sample.
%
% @param Sample *list of number*
% @param Min *number*
% @param Max *number*

%! range(+Sample, -Value)
%
% is true when Value is the difference between the largest and smallest elements of Sample.
%
% @param Sample *list of number*
% @param Value *number*

%! mode(+Sample, -Values)
%
% is true when Values is the most frequently occurring value(s) in Sample.
% If there is a unique value with maximum frequency, this value is returned as the only element of Values.
% Otherwise, Values contains the maximum frequency elements in increasing order.
% This predicate does not make much sense if the sample is continuous.
%
% @param Sample *list of number*
% @param Values *list of number*

%! mean(+Sample, -Value)
%
% is true when Value is the arithmetic mean of Sample.
%
% @param Sample *list of number*
% @param Value *number*

%! arithmetic_mean(+Sample, -Value)
%
% is true when Value is the arithmetic mean of Sample.
%
% @param Sample *list of number*
% @param Value *number*

%! weighted_mean(+Weight, +Sample, -Value)
%
% is true when Value is the arithmetic mean of Sample weighted by Weight.
%
% @param Weight *list of number*
% @param Sample *list of number*
% @param Value *number*

%! geometric_mean(+Sample, -Value)
%
% is true when Value is the geometric mean of Sample.
%
% @param Sample *list of number*
% @param Value *number*

%! harmonic_mean(+Sample, -Value)
%
% is true when Value is the harmonic mean of Sample.
%
% @param Sample *list of number*
% @param Value *number*

%! central_moment(+K, +Sample, -Value)
%
% is true when Value is the K-th central moment of Sample.
% Also known as the K-th central moment about the mean.
% K should be positive integer.
%
% @param K *integer*
% @param Sample *list of number*
% @param Value *number*

%! skewness(+Sample, -Value)
%
% is true when Value is the skewness of Sample.
% This is a measure of the asymmetry of its distribution.
% A sample with negative skew is said to be *left-skewed*.
% Most of its mass is on the right of the distribution, with the tail on the left.
% Vice versa for positive skew.
% A sample's skewness is undefined if its variance is zero.
%
% @param Sample *list of number*
% @param Value *number*

%! kurtosis(+Sample, -Value)
%
% is true when Value is the excess kurtosis of Sample.
% This is a measure of the peakedness of its distribution.
% A high kurtosis indicates that most of the sample's variance is
% due to infrequent severe deviations, rather than frequent modest deviations.
% A sample's excess kurtosis is undefined if its variance is zero.
% In this implementation, the kurtosis of the normal distribution is 0.
%
% @param Sample *list of number*
% @param Value *number*

%! ml_variance(+Sample, -Value)
%
% is true when Value is the maximum likelihood estimate of the variance of Sample.
% Also known as the population variance, where the denominator is the length of Sample.
%
% @param Sample *list of number*
% @param Value *number*

%! population_variance(+Sample, -Value)
%
% is true when Value is the maximum likelihood estimate of the variance of Sample.
% Also known as the population variance, where the denominator is the length of Sample.
%
% @param Sample *list of number*
% @param Value *number*

%! sample_variance(+Sample, -Value)
%
% is true when Value is the unbiased estimate of the variance of Sample.
% Also known as the sample variance, where the denominator is the length of Sample minus one.
%
% @param Sample *list of number*
% @param Value *number*

%! unbiased_variance(+Sample, -Value)
%
% is true when Value is the unbiased estimate of the variance of Sample.
% Also known as the sample variance, where the denominator is the length of Sample minus one.
%
% @param Sample *list of number*
% @param Value *number*

%! weighted_variance(+Weight, +Sample, -Value)
%
% is true when Value is the weighted (biased) estimate of the variance of Sample.
%
% @param Weight *list of number*
% @param Sample *list of number*
% @param Value *number*

%! ml_standard_deviation(+Sample, -Value)
%
% is true when Value is the maximum likelihood estimate of the standard deviation of Sample.
% Also known as the population standard deviation, where the denominator is the length of Sample.
% Equals the square root of the population variance.
%
% @param Sample *list of number*
% @param Value *number*

%! population_standard_deviation(+Sample, -Value)
%
% is true when Value is the maximum likelihood estimate of the standard deviation of Sample.
% Also known as the population standard deviation, where the denominator is the length of Sample.
% Equals the square root of the population variance.
%
% @param Sample *list of number*
% @param Value *number*

%! sample_standard_deviation(+Sample, -Value)
%
% is true when Value is the unbiased estimate of the standard deviation of Sample.
% Also known as the sample standard deviation, where the denominator is the length of Sample minus one.
% Equals the square root of the sample variance.
%
% @param Sample *list of number*
% @param Value *number*

%! unbiased_standard_deviation(+Sample, -Value)
%
% is true when Value is the unbiased estimate of the standard deviation of Sample.
% Also known as the sample standard deviation, where the denominator is the length of Sample minus one.
% Equals the square root of the sample variance.
%
% @param Sample *list of number*
% @param Value *number*

%! weighted_standard_deviation(+Weight, +Sample, -Value)
%
% is true when Value is the weighted (biased) estimate of the standard deviation of Sample.
% Equals the square root of the weighted (biased) variance.
%
% @param Weight *list of number*
% @param Sample *list of number*
% @param Value *number*

%! covariance(+Sample1, +Sample2, -Value)
%
% is true when Value is the covariance of Sample1 and Sample2.
%
% @param Sample1 *list of number*
% @param Sample2 *list of number*
% @param Value *number*

%! correlation(+Sample1, +Sample2, -Value)
%
% is true when Value is the correlation of Sample1 and Sample2.
% If there is no variance in Sample1 or in Sample2, an error is raised.
%
% @param Sample1 *list of number*
% @param Sample2 *list of number*
% @param Value *number*

%! median(+Sample, -Value)
%
% is true when Value is the median of Sample, that is,
% the value separating the higher half of the sample from the lower half.
% If there are an even number of observations, then the median is defined to be the smaller middle value.
% Same as the 0.5-fractile of Sample.
%
% @param Sample *list of number*
% @param Value *number*

%! fractile(+P, +Sample, -Value)
%
% is true when Value is the P-fractile of Sample, that is,
% the smallest value in the sample such that the fraction P of the sample is less than or equal to that value.
% P should be a number in (0.0,1.0].
%
% @param P *number*
% @param Sample *list of number*
% @param Value *number*

%! normalize(+Sample, -Normalized)
%
% is true when Normalized is the normalized Sample, so that
% Normalized has a mean of 0 and a population standard deviation of 1.
%
% @param Sample *list of number*
% @param Normalized *list of number*
