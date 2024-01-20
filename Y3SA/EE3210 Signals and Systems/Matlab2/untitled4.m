x0=0.3042;
x1=-0.8509;
x2=-1.9444;
w=acosd((x2+x0)/(2.*x1));
phi=atand((cosd(w)-(x1./x0))/sind(w));
a=x2./(cosd(2.*w+phi));