%% FIR Digital Filter
num = 1;
den=[1 3 3 1 4];
sys = filt(num,den,2E-5);
isstable(sys)
damp(sys)
figure(1)
bode(sys)
figure(2)
pzplot(sys)