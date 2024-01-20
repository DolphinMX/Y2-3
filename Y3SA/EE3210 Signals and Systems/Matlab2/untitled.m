clear all
Fs=8000;
Ts=1/Fs;
t=[0:Ts:0.5];
F_A=440;
A=sin(2*pi*F_A*t);
sound(A, Fs);
[freq_resp, freq_index]=freqz(A,1,50000,Fs);
plot(freq_index,abs(freq_resp))
xlabel('Frequency in Hz')

% Find the dominant frequency
[max_val, max_index] = max(abs(freq_resp));
dominant_freq = freq_index(max_index);
fprintf('The dominant frequency is: %.2f Hz\n', dominant_freq);