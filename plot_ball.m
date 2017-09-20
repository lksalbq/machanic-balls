load('ball.txt');
figure;
% hold on; 
axis([-1, 1, -1, 0])
for c=1:size(ball,1),
 	 plot(ball(c,1), ball(c,2), 'o', 'MarkerSize', 20, 'LineWidth', 5);
   axis([-1, 1, -1, 0])
   pause(.01);
end
