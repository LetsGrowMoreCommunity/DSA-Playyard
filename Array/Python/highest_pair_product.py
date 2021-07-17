# Problem: 
# Given an array, return the pair with the highest product
# Elements in the array are only integers and can have both positive & negative values

# For example 
# Original array: [-1, 2, 0, 4, 9, 0, 10, 4]
# Maximum product pair is: (9, 10) or (10, 9)
# Original array: [0, 1, -2, -6, 5, 0, -6]
# Maximum product pair is: (-6, -6)

# Explanation: 
# To solve this in a linear time complexity we need to identify that the product between  2 
# positive numbers will be a positive number, and the product between 2 negative numbers
# will also be a positive number. Knowing this we can deduct that we would get the highest product
# between the highest 2 positive numbers but also we could get the product from the 2 most
# lowest negative numbers. What we need is 2 variables which will hold the maximmum pair for both
# the lowest 2 negative numbers only and the maxximum pair for the highest 2 positive numbers only.

# Solved in: 
# O(n) - time complexity
# O(1) - space complexity

# input: [] - list
# output: () - tuple
def highest_pair_product(arr):
    
    # if the length of the array is less than 2, then return an empty tuple
    # if the length of the array is equal to 2, then return the elements as tuple
    if (len(arr) < 2):
        return ()
    elif (len(arr) == 2):
        return tuple(arr)
        
    # create 2 lists which will hold the positive & negative pairs for the highest product 
    # default values will be 0, so it will be easier to change the values later on
    poz_pair = [0, 0]
    neg_pair = [0, 0]
    
    # start iterating each item in the input list
    for number in arr:
        
        # 0 values are not important in this case so we can skip
        if number == 0:
            continue
        
        # we now try to find if the number in the input list will replace a number 
        # in the neg_pair list
        # this, in the end will have the maximmum product between negative numbers only
        elif number < 0:
            
            # if the neg_pair list has the default values, we can change the default
            # value with the current number, after asigning, we are done with the 
            # current number operations and can continue with the next number in the list
            if neg_pair[0] == 0:
                neg_pair[0] = number
                continue
            elif neg_pair[1] == 0:
                neg_pair[1] = number
                continue
            
            # get the product between the 2 elements of the negative pair
            max_prod = neg_pair[0] * neg_pair[1]
    
            # for the first case, we check if the current number multiplied by the first value in
            # neg_pair is greater then the product of the current number and the second value in
            # neg_pair and also if the product of current number with the first value in neg_pair
            # is greater than the old maximmum product between first and second value in neg_pair
            if number * neg_pair[0] > number * neg_pair[1] and number * neg_pair[0] > max_prod:
                
                # if the whole statement is true, then we can assign a new value to the second 
                # value in neg_pair which will be the current number
                neg_pair[1] = number
            
            # this statement will basically check if we would to change the first value in 
            # neg_pair, would the product be greater than the product checked in the first if
            # statement and also the product would be greater than the old maximmum product from
            # before.
            elif number * neg_pair[1] > number * neg_pair[0] and number * neg_pair[1] > max_prod:
                
                # if the product will be greater in this case, then the first value of the 
                # neg_pair will be changed to the current number
                neg_pair[0] = number
                
        # this will check the case only for positive integers in the current number
        # this has basically the same logic with the case explained above but applied
        # for the positive pair list 
        # this, in the end will have the maximmum product between positive numbers only
        else: 
            if poz_pair[0] == 0:
                poz_pair[0] = number
                continue
            elif poz_pair[1] == 0:
                poz_pair[1] = number
                continue
            
            max_prod = poz_pair[0] * poz_pair[1]
            
            if number * poz_pair[0] > number * poz_pair[1] and number * poz_pair[0] > max_prod:
                poz_pair[1] = number
            elif number * poz_pair[1] > number * poz_pair[0] and number * poz_pair[1] > max_prod:
                poz_pair[0] = number
          
         
    # calculate the product between the both positive and negative pairs list
    max_prod_poz = poz_pair[0] * poz_pair[1]
    max_prod_neg = neg_pair[0] * neg_pair[1]
    
    # if the product for the positive pair is greater than the product between negative pair
    # return the tuple from the positive pair
    # else return the tuple from  the negative pair
    if max_prod_poz >= max_prod_neg:
        return tuple(poz_pair)
    else:
        return tuple(neg_pair)
        
print(highest_pair_product([])) # out: empty tuple ()
print(highest_pair_product([0])) # out: ()
print(highest_pair_product([-1, -1])) # out: (-1, -1)
print(highest_pair_product([2, 1])) # out: (2, 1)
print(highest_pair_product([6, -1, 2])) # out: (6, 2)
print(highest_pair_product([-2, -3, 7])) # out: (-2, -3) 
print(highest_pair_product([-1, -2, 2, 1])) # out: (2, 1) or (-1, -2), both are correct
print(highest_pair_product([0, -1, 0, 0, 0, 1])) # out: (0, 1)
print(highest_pair_product([-2, -1, -8, 7, 1, -5])) # out: (-5, -8)
print(highest_pair_product([1, 2, 3, 4, 5, 6, 7, 8, 9])) # out: (9, 8)
print(highest_pair_product([-1, 2, 0, 4, 9, 0, 10, 4])) # out: (9, 10)
print(highest_pair_product([0, 1, -2, -6, 5, 0, -6])) # out: (-6, -6)
print(highest_pair_product([100, 200, 300, -300, -200, -100])) # out: (200, 300)
print(highest_pair_product([100, 200, 300, -301, -200, -100])) # out: (-301, -200)