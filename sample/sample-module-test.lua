-- Example: Sample Library
--[[Description:
Demonstrate the use of the sample library
]]

local sum

function love.load()
    love.graphics.setFont(love.graphics.newFont(11))

    -- Will display all the modules loaded onto the console.
    for key,value in pairs(love) do
        print("found member " .. key);
    end
    
    -- Will use the `doSum` function for the `love.sample` module
    sum = love.sample.doSum(2, 4)
end

function love.draw()
    -- Draws the position on screen.
    love.graphics.print("The sum is " .. sum, 50, 50)
end
