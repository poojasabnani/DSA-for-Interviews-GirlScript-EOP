# DSA DAY 7

## Topics Covered

Divide and Conquer Algorithms

## Theory

[Divide and Conquer Algorithms](https://github.com/py93/DSA-for-Interviews-GirlScript-EOP/blob/master/Day%207/Divide%20and%20Conquer.pptx?raw=true)

## Quiz

[Take the Quiz](https://forms.gle/aRVxwUMHGLGNBgtK9)

## Solved Problems

#### PROBLEM: 

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
	
#### Thinking statergy :

DIVIDE AND CONQUER:

* case 1 : The largest rectange may be present in the left part or
* case 2 : the largest rectange may be present in the right part or
* case 3 : the largest rectange may be some part of left and some part of right
	
The first two problems can be solved using recursion and we just need to handle the third case. (in the code we did that case using helper() function.


```c


// THIS IS THE HELPER FUNCTION... TO HANDLE THE CASE 3
long helper(vector<int> h , long  ind,long s, long e){
    long mprod = h[ind];
    long prod = 1;
    long left = ind -1;
    long right = ind + 1;
    long ht = h[ind];
    long cnt = 1;
    while(left>= s and right<=e){
        if(h[left]>h[right]){
            ht = min(ht,(long)h[left]);
            cnt++;
            prod = ht*cnt;
            mprod = max(prod,mprod);
            left--;
        }
        else if (h[right]>=h[left]){
            ht = min(ht,(long)h[right]);
            cnt++;
            prod = ht*cnt;
            mprod = max(prod,mprod);
            right++;
        }
    }
    while(left>=s){
        cnt++;
        ht = min(ht,(long)h[left]);
        prod = ht*cnt;
        mprod = max(prod,mprod);
        left--;
    }
    while(right<=e){
        cnt++;
        ht = min(ht,(long)h[right]);
        prod = ht*cnt;
        mprod = max(prod,mprod);
        right++;
    }
    return max(mprod,(long)h[ind]);
}
// THIS FUNCTION WILL BE CALLED BY MAIN FUNCTION...
long _largestRectangle(vector<int> h, long s , long e ) {
    if(s>e){
        return 0;
    }
    if(e == s+1){
        return max({h[s],h[e],min(h[e],h[s])*2});
    }
    if(s == e){ // re-look
        return h[s];
    }
    long mid = (s+e)/2;
    long left = _largestRectangle(h,s,mid-1);
    long right = _largestRectangle(h,mid+1,e);
    long both = helper(h,mid,s,e);
    return max({left , right , both});

}

```
