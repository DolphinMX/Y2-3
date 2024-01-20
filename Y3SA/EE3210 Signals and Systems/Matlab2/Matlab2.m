% Given values
omega = 0.27;
x0 = 0.3042;
x1 = -0.8509;
x2 = -1.9444;

% Solve for ϕ
phi = acos(x0); % arccos of x0

% Solve for A
A = x0 / cos(phi);

% Display the results
phi_degrees = rad2deg(phi);
fprintf('ϕ ≈ %.4f radians or ϕ ≈ %.2f degrees\n', phi, phi_degrees);
fprintf('A ≈ %.4f\n', A);