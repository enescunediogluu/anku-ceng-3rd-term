 %x=0:1:20;
 %y=x.^3-x.^2;
 %plot(x,y);
% ==================================

x=0:pi/20:2*pi;
y1=sin(2*x);
y2=2*cos(2*x);
plot(x,y1,x,y2);
% ==================================

% x=0:pi/20:2*pi;
% y=sin(2*x);
% plot(x,y);
% title('sin(2x) chart');
% xlabel('Angles');
% ylabel('sin(2x)');
% ==================================

% x=0:pi/20:2*pi;
% plot(x,sin(x),'-.r')
%
% x=0:pi/20:2*pi;
% plot(x,sin(x),'-.r*')
% ==================================

% plot(x,sin(x), 'LineStyle','--',...
%       'Color','m',...
%       'LineWidth', 2,...
%       'Marker','o',...
%       'MarkerEdgeColor','r',...
%       'MarkerFaceColor','g',...
%       'MarkerSize',15)
% ==================================

% x = 0:pi/20:2*pi;
% plot(x,sin(x),':bs',x,cos(2*x),'--mo')
% ==================================

% x = 0:pi/20:2*pi;
% plot(x,sin(x),':bs')
% hold on
% plot(x,cos(2*x),'--mo')
% ==================================

% x = 0:pi/20:2*pi;
% plot(x,sin(x))
% grid on
% ==================================

% x = 0:pi/20:2*pi;
% plot(x,sin(x),':g+')
% axis([0 2*pi -1.5 1.5])
% ==================================

% sprintf("The maximum number is %d",functionExample(10,20,-3))
% temp=functionExample(10,20,-3);
% fprintf("The maximum number:\n%10d ",temp);
% ==================================

% temp=functionExample2([10 20 -3;100 -50 27]);
% fprintf("The maximum number in the matrix:\n%d ",temp);
% ==================================

% temp=functionExample3();
% fprintf("The sum of the numbers between 1 and 10:\n%d ",temp);
