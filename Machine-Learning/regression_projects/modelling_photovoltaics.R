dataset = read.csv("tabela.csv", sep = ';')

# Polynomial Regression
for (i in seq(2,8)){
  col_name = paste0("Month", i)
  dataset[[col_name]] = dataset$Month^i
}

# Fitting the model
pol_reg = lm(formula = Produced ~., data = dataset)

y_pred_pol = predict(pol_reg, newdata = dataset[-2])

# Visualisation
library(ggplot2)
ggplot() +
  geom_point(aes(x = dataset$Month, y = dataset$Produced),
             colour = 'red') +
  geom_line(aes(x = dataset$Month, y = predict(pol_reg, newdata = dataset)),
            colour = 'blue') +
  ggtitle("Polynomial Regression") +
  xlab("Month") +
  ylab("Produced")

summary(pol_reg)$r.squared

new_data = data.frame(Month = c(8:12))
for (i in seq(2, 8)){
  col_name = paste0("Month", i)
  new_data[[col_name]] = new_data$Month^i
}
prediction = predict(pol_reg, newdata = new_data)

sum_produced = sum(prediction)
annual_produced = 2876 + sum_produced
sell = annual_produced*0.815*0.28
other = annual_produced*0.185*1.33
predicted_saving = sell + other #2291.557 zł

############################################################################33
# # Random Forest Regression
# dataset = read.csv("tabela.csv", sep = ';')
# 
# #Fitting the model
# library(randomForest)
# for_reg = randomForest(x = dataset[1],
#                        y = dataset$Produced,
#                        ntree = 500)
# 
# y_pred_for = predict(for_reg, dataset)
# 
# # Visualisation
# x_grid = seq(min(dataset$Month), max(dataset$Month), 0.01)
# ggplot() +
#   geom_point(aes(x = dataset$Month, y = dataset$Produced),
#              colour = 'red') +
#   geom_line(aes(x = x_grid, y = predict(for_reg, newdata = data.frame(Month = x_grid))),
#             colour = 'blue') +
#   ggtitle("Random Forest Regression") +
#   xlab("Month") +
#   ylab("Produced")
