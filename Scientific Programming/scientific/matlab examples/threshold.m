function output = threshold(img, thresholdValue)
    % Get the size of the input image
    [rows, cols] = size(img);

    % Initialize the output image with zeros
    output = zeros(rows, cols);

    % Loop through each pixel
    for i = 1:rows
        for j = 1:cols
            % Apply the thresholding
            if img(i, j) > thresholdValue
                output(i, j) = 255;
            end
        end
    end
end

