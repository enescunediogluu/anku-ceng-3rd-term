function [result,opName] =functionOperation(param1,param2,param3)

    if param3=="+"
        result=param1+param2;
        opName="Addition";

    elseif param3=="-"
        result=param1-param2;
        opName="Subtraction";
    end 
    
    prompt="this prompt was written in the function!";
    fprintf(prompt+"\n");
end