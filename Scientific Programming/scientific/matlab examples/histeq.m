% Read the image
image = imread('human.jpg');

% Convert the image to grayscale if it's a color image
if size(image, 3) == 3
    image = rgb2gray(image);
end

% Initialize an array to store the histogram
histogram = zeros(256, 1);

% Iterate through each pixel and update the histogram
[rows, cols] = size(image);
for i = 1:rows
    for j = 1:cols
        pixel_value = image(i, j);
        histogram(pixel_value + 1) = histogram(pixel_value + 1) + 1;
    end
end

% Plot the histogram
bar(histogram, 'BarWidth', 1, 'FaceColor', 'b');
title('Image Histogram (Manual)');
xlabel('Pixel Value');
ylabel('Frequency');
grid on;

