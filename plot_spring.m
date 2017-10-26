X = load('x.txt');
figure;
hold on; 
axis([-1, 1, -1, 1])
for c=1:size(X,1),
   plot(X(c,1), X(c,2), 'o', 'MarkerSize', 20, 'LineWidth', 5);
   axis([-1, 1, -1, 1])
   hold on
   plot(X(c,3), X(c,4), '*', 'MarkerSize', 20, 'LineWidth', 5);
   plot([X(c,1) X(c,3)], [X(c,2) X(c,4)], '-', 'LineWidth', 5);
   title(sprintf("Energia = %d", X(c,5)));
   pause(.01);
   %hold off;
end
