-- Example: Sample Library
--[[Description:
Demonstrate the use of the sample library
]]

function love.load()
    love.graphics.setFont(love.graphics.newFont(11))
end

function love.draw()
    -- Gets the x- and y-position of the mouse.
    local x = 50
    local y = 50

    -- Will display all the modules loaded onto the console.
    for key,value in pairs(love) do
        print("found member " .. key);
    end

    -- Will use the `doSum` function for the `love.sample` module
    local sum = love.sample.doSum(2, 4)

    -- Draws the position on screen.
    love.graphics.print("The sum is " .. sum, 50, 50)
end