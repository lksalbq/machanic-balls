load x.txt;
figure; 
for c=1:size(x,3),
 	 plot(x(c,1), x(c,2), '@', 'MarkerSize', 20, 'LineWidth', 5);
 	 axis([-1, 1, -1, 0])
 	 hold on	
 	 plot(x(c,3), x(c,4), '@', 'MarkerSize', 20, 'LineWidth', 5);
 	 plot([x(c,1) x(c,3)],[x(c,2) x(c,4)],'-', 'LineWidth', 5);
   pause(.01);
   hold off;
end
