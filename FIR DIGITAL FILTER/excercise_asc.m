

den = int16(1);

num=int16([1 3 3 1 4]);

t=linspace(0,1,4096);
x=2000*sin(2*pi*t)+2000;
filter_for_mew(num,den,x);