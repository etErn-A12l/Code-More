//A simple ripple carry adder

int adder(int x, int y)
{
    int carry = 0;
    int result = 0;
  
    //Loop through each bit
    for (int i=0; i<32; i++)
    {
        //Get the current bit from x and y
        int x_bit = x & (1 << i);
        int y_bit = y & (1 << i);
 
        if (x_bit ^ y_bit ^ carry) 
            result |= (1 << i);
 
        //Calculate the new carry
        carry = (x_bit & y_bit) | (x_bit & carry) | (y_bit & carry);
    }
 
    return result;
}
