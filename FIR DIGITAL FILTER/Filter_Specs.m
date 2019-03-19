%% FIR Digital Filter
% Filter Coefficients
den = 1;
num=[1 3 3 1 4];
Ts=2E-5;

% Original Sine Wave
t=linspace(0,1,4096);
x=2000*sin(2*pi*t)+2000;

% Transfer Function and Filtering System
H=tf(num,den);
sys = filt(num,den,Ts);

% Filtering the oringal sine wave

% Quick check if stable
isstable(sys)

%% Plotting Secion

figure(1)
options = bodeoptions;
options.FreqUnits = 'Hz';
bode(sys,options)
title('Bode Plot');


figure(2)
pzplot(sys)
figure(3)
freqz(num,den,4097)

y = filter(num,den,x);

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
