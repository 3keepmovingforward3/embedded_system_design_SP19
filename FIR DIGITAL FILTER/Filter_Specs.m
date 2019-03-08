%% FIR Digital Filter
num = 1;
den=[1 3 3 1 4];
[u,t]=gensig('sin',0.00676);
H=tf(num,den);
sys = filt(num,den,2E-5);
isstable(sys)
damp(sys)
figure(1)
options = bodeoptions;
options.FreqUnits = 'Hz';
bode(sys,options)
figure(2)
pzplot(sys)
figure(3)
lsim(H,u,t)