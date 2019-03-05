funcstr = 'sin(2*pi*x)'; % Define the sine function
xmin = 0.0; % Set the minimum input of interest
xmax = 1.0; % Set the maximum input of interest
xdt = fixdt(0,16); % Set the x data type
xscale = 2^-16; % Set the x data scaling
ydt = fixdt(1,16); % Set the y data type
yscale = 2^-14; % Set the y data scaling
rndmeth = 'Floor'; % Set the rounding method
nptsmax = 4096; % Specify the maximum number of points

[xdata, ydata, errworst] = fixpt_look1_func_approx(funcstr, ...
xmin,xmax,xdt,xscale,ydt,yscale,rndmeth,[],nptsmax);

fixpt_look1_func_plot(xdata,ydata,funcstr,xmin,xmax,xdt, ...
xscale,ydt,yscale,rndmeth);