New_Fs=4000;
sound(A, New_Fs);
[freq_resp,freq_index]=freqz(A,1,50000, New_Fs);
plot(freq_index,abs(freq_resp))
xlabel('Frequency in Hz')