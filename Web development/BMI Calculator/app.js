const unitSelect = document.getElementById('unit');
        const heightInput = document.getElementById('height');
        const weightInput = document.getElementById('weight');
        const heightUnit = document.getElementById('height-unit');
        const weightUnit = document.getElementById('weight-unit');
        const calculateBtn = document.getElementById('calculate');
        const resetBtn = document.getElementById('reset');
        const resultDiv = document.getElementById('result');

        unitSelect.addEventListener('change', updateUnits);
        calculateBtn.addEventListener('click', calculateBMI);
        resetBtn.addEventListener('click', resetCalculator);

        function updateUnits() {
            if (unitSelect.value === 'metric') {
                heightUnit.textContent = 'cm';
                weightUnit.textContent = 'kg';
            } else {
                heightUnit.textContent = 'in';
                weightUnit.textContent = 'lbs';
            }
        }

        function calculateBMI() {
            const height = parseFloat(heightInput.value);
            const weight = parseFloat(weightInput.value);

            if (isNaN(height) || isNaN(weight) || height <= 0 || weight <= 0) {
                resultDiv.innerHTML = '<p class="error">Please enter valid height and weight values.</p>';
                return;
            }

            let bmi;
            if (unitSelect.value === 'metric') {
                bmi = weight / ((height / 100) ** 2);
            } else {
                bmi = (weight / (height ** 2)) * 703;
            }

            const category = getBMICategory(bmi);
            resultDiv.innerHTML = `
                <p>Your BMI is ${bmi.toFixed(1)}</p>
                <p>Category: ${category}</p>
            `;
        }

        function getBMICategory(bmi) {
            if (bmi < 18.5) return 'Underweight';
            if (bmi < 25) return 'Normal weight';
            if (bmi < 30) return 'Overweight';
            return 'Obesity';
        }

        function resetCalculator() {
            heightInput.value = '';
            weightInput.value = '';
            resultDiv.innerHTML = '';
            unitSelect.value = 'metric';
            updateUnits();
        }