%% FIR Digital Filter
den = [1 0.25];
num=[1 3 3 1 4];
t=linspace(0,1,4096);
H=tf(num,den);
sys = filt(num,den,2E-5);
isstable(sys)
x=2000*sin(2*pi*t)+2000;
figure(1)
options = bodeoptions;
options.FreqUnits = 'Hz';
bode(sys,options)
figure(2)
pzplot(sys)
figure(3)
freqz(num,den,4096)

y = filter_for_mew(num,den,x);

figure(4)
plot(t,x)
yyaxis left
ylim([-2000 49000]);
hold on
plot(t,y)
yyaxis right
ylim([-2000 0]);
legend('Input Data','Filtered Data')
hold off
