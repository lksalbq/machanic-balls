ball = textread ('ball.txt');
figure;
axis([-1, 1, -1, 0])
for c=1:size(ball,1),
 	plot(ball(c,1), ball(c,2),'o', 'MarkerSize', 20, 'LineWidth', 5);
 	axis([-1, 1, -1, 0])
 	hold on;
 	plot(ball(c,3), ball(c,4), 'o', 'MarkerSize', 20, 'LineWidth', 5);
 	plot([ball(c,1) ball(c,3)],[ball(c,2) ball(c,4)],'o','-','MarkerSize', 20, 'LineWidth', 5);
   pause(.01);
   hold off;
end